class ball:
    def __init__(self, mass, radius):
        self.m = mass
        self.r = radius
    def getM1(self):
        return self.m
    def getR1(self):
        return self.r
    def getI1(self):
        return (2/5)*self.m * (self.r)**2