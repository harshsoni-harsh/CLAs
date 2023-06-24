from numpy import *
from path import path
from ball import ball
from matplotlib.pyplot import *
from matplotlib.animation import FuncAnimation
# from pylab import *
from time import sleep

class Baton:
    def __init__(self, mass, radius, v0, theta, l, w):
        path.__init__(path, v0, theta)
        ball.__init__(ball, mass, radius)
        self.l = l
        self.w = w
    def getM(self):
        return 2*ball.getM1(self)
    def getI(self):
        return 2*ball.getI1(self) + 0.5 * ball.getM1(self) * self.L ** 2

    def getXa(self,t):
        return path.getX(path, t) + 0.5 * self.l * cos(self.w * t)
    def getYa(self, t):
        return path.getY(path, t) + 0.5 * self.l * sin(self.w * t)
    
    def getXb(self,t):
        return path.getX(path, t) - 0.5 * self.l * cos(self.w * t)
    def getYb(self, t):
        return path.getY(path, t) - 0.5 * self.l * sin(self.w * t)

    def getXc(self,t):
        return path.getX(path, t)
    def getYc(self, t):
        return path.getY(path, t)
    
    def position(self):
        t=0.0
        count=4
        xao = self.getXa(t)
        yao = self.getYa(t)
        xbo = self.getXb(t)
        ybo = self.getYb(t)
        xco = self.getXc(t)
        yco = self.getYc(t)
        t+=0.02
        while(self.getYa(t) >= 0.0):
            xa = self.getXa(t)
            ya = self.getYa(t)
            xb = self.getXb(t)
            yb = self.getYb(t)
            print(ya, t, count)
            xc = self.getXc(t)
            yc = self.getYc(t)
            
            plot([xao, xa], [yao, ya], '-or')
            plot([xbo, xb], [ybo, yb], '-ob')
            plot([xa, xb], [ya, yb], 'm')
            plot([xco, xc], [yco, yc], 'k')

            xao = xa
            yao=ya
            xbo = xb
            ybo=yb
            xco=xc
            yco=yc
            t+=0.02
            count+=1
        show()

        
mybaton = Baton(0.5,0.5,15.0,45.0,2.5,22.0)
mybaton.position()