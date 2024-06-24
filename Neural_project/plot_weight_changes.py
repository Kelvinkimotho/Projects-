import numpy as np
import matplotlib.pyplot as plt
from simulate_neurons import time, update_weights

# Recording synaptic weight changes for plotting
weights_d1 = [update_weights(0.5, np.sin(t / 10.0), 'd1') for t in range(len(time))]
weights_d2 = [update_weights(0.5, np.sin(t / 10.0), 'd2') for t in range(len(time))]

# Function to plot and save synaptic weight changes
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

# Plotting and saving synaptic weight changes
plot_weights(time, weights_d1, 'weights_d1.png')
plot_weights(time, weights_d2, 'weights_d2.png')
