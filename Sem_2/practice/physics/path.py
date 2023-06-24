import math

class path:
    def __init__(self, v0, theta):
        self.g = 9.8
        self.v0 = v0
        self.theta = theta
        self.v0x = self.v0 * math.cos(self.theta * math.pi/180.0)
        self.v0y = self.v0 * math.sin(self.theta * math.pi/180.0)
    
    def getX(self, t):
        self.t = t
        return self.v0x * self.t
    
    def getY(self, t):
        self.t = t
        return self.v0y * self.t - 0.5 * self.g * (self.t)**2
