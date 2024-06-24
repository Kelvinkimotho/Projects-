import numpy as np
import matplotlib.pyplot as plt

class IzhikevichNeuron:
    def __init__(self, C, vr, vt, vpeak, a, b, c, d, k):
        self.C = C
        self.vr = vr
        self.vt = vt
        self.vpeak = vpeak
        self.a = a
        self.b = b
        self.c = c
        self.d = d
        self.k = k
        self.v = vr
        self.u = 0

    def step(self, I, dt=1.0):
        if self.v >= self.vpeak:
            self.v = self.c
            self.u += self.d
        dv = (self.k * (self.v - self.vr) * (self.v - self.vt) - self.u + I) / self.C
        du = self.a * (self.b * (self.v - self.vr) - self.u)
        self.v += dv * dt
        self.u += du * dt
        return self.v

# Parameters for the neurons
params_d1_d2 = {'C': 50, 'vr': -80, 'vt': -25, 'vpeak': 40, 'a': 0.01, 'b': -20, 'c': -55, 'd': 150, 'k': 1}
params_rs = {'C': 100, 'vr': -60, 'vt': -40, 'vpeak': 35, 'a': 0.03, 'b': -2, 'c': -50, 'd': 100, 'k': 0.7}

# Creating neurons
d1_neuron = IzhikevichNeuron(**params_d1_d2)
d2_neuron = IzhikevichNeuron(**params_d1_d2)
regular_neuron = IzhikevichNeuron(**params_rs)

# Simulating neuron responses
time = np.arange(0, 150, 1)
I_zigzag = np.concatenate([np.linspace(0, 20, 50), np.linspace(20, 0, 50), np.linspace(0, 20, 50)])

# Initializing synaptic weights
w_ctx_d1 = 0.5
w_ctx_d2 = 0.5
alpha = 0.01  # this is the learning rate

# Dopamine effects on synaptic plasticity
def update_weights(w, delta_da, neuron_type):
    if neuron_type == 'd1':
        if delta_da > 0:
            w += alpha * delta_da  # LTP for D1 neurons
        else:
            w -= alpha * abs(delta_da)  # LTD for D1 neurons
    elif neuron_type == 'd2':
        if delta_da > 0:
            w -= alpha * delta_da  # LTD for D2 neurons
        else:
            w += alpha * abs(delta_da)  # LTP for D2 neurons
    return w

# Recording membrane potentials
v_d1 = []
v_d2 = []
v_rs = []

# Simulating learning and synaptic weight changes
for t in range(len(time)):
    # Updating input currents based on synaptic weights
    I_d1 = w_ctx_d1 * I_zigzag[t]
    I_d2 = w_ctx_d2 * I_zigzag[t]

    # Stepping  through each neuron
    v_d1.append(d1_neuron.step(I_d1))
    v_d2.append(d2_neuron.step(I_d2))
    v_rs.append(regular_neuron.step(I_zigzag[t]))

    # Simulating dopamine signal example: positive prediction error
    delta_da = np.sin(t / 10.0)  # sinusoidal DA signal for illustration

    # Updating synaptic weights
    w_ctx_d1 = update_weights(w_ctx_d1, delta_da, 'd1')
    w_ctx_d2 = update_weights(w_ctx_d2, delta_da, 'd2')

# Function to plot and save each neuron response
def plot_and_save(time, voltage, neuron_type, filename):
    plt.figure(figsize=(10, 5))
    plt.plot(time, voltage, label=f'{neuron_type} Neuron', color='blue')
    plt.xlabel('Time (ms)')
    plt.ylabel('Membrane Potential (mV)')
    plt.title(f'{neuron_type} Neuron Response')
    plt.legend()
    plt.grid(True)
    plt.savefig(filename)
    plt.show()

# Plotting  and save each neuron's response
plot_and_save(time, v_d1, 'D1', 'd1_neuron_response.png')
plot_and_save(time, v_d2, 'D2', 'd2_neuron_response.png')
plot_and_save(time, v_rs, 'Regular Spiking', 'regular_neuron_response.png')

# Ploting and save synaptic weight changes
def plot_weights(time, weights, filename):
    plt.figure(figsize=(10, 5))
    plt.plot(time, weights, label='Synaptic Weights', color='green')
    plt.xlabel('Time (ms)')
    plt.ylabel('Weight')
    plt.title('Synaptic Weight Changes Over Time')
    plt.legend()
    plt.grid(True)
    plt.savefig(filename)
    plt.show()

# Recording synaptic weight changes for plotting
weights_d1 = [update_weights(0.5, np.sin(t / 10.0), 'd1') for t in range(len(time))]
weights_d2 = [update_weights(0.5, np.sin(t / 10.0), 'd2') for t in range(len(time))]

plot_weights(time, weights_d1, 'weights_d1.png')
plot_weights(time, weights_d2, 'weights_d2.png')
