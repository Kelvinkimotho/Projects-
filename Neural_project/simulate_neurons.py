import numpy as np
from izhikevich_neuron import IzhikevichNeuron

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

    # Stepping through each neuron
    v_d1.append(d1_neuron.step(I_d1))
    v_d2.append(d2_neuron.step(I_d2))
    v_rs.append(regular_neuron.step(I_zigzag[t]))

    # Simulating dopamine signal example: positive prediction error
    delta_da = np.sin(t / 10.0)  # sinusoidal DA signal for illustration

    # Updating synaptic weights
    w_ctx_d1 = update_weights(w_ctx_d1, delta_da, 'd1')
    w_ctx_d2 = update_weights(w_ctx_d2, delta_da, 'd2')
