import numpy as np

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
