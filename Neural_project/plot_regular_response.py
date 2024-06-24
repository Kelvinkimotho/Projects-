import matplotlib.pyplot as plt
from simulate_neurons import time, v_rs

# Function to plot and save the regular spiking neuron response
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

# Plotting and saving regular spiking neuron response
plot_and_save(time, v_rs, 'Regular Spiking', 'regular_neuron_response.png')
