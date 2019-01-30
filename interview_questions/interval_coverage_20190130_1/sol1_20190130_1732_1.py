# Print Your code here
# Problem Statement: 
# - the `Drop` class represents a segment with random center and random extension  
# - compute how many drops are necessary to fully cover the [0,1] interval 
from random import randrange, uniform

class Drop: 
    def __init__(self, x, r): 
        self.x=x
        self.r=r
    def to_str(self): 
        return "Drop (" + str(self.x) + ", r=" + str(self.r) + ")"

class Segment: 
    def __init__(self, m1, m2): 
        self.m1 = m1
        self.m2 = m2
    def is_inside(self, x): 
        if( (x>=self.m1) and (x<=self.m2) ): return True 
        return False

    def to_str(self): 
        return "S (" + str(self.m1) + ", " + str(self.m2) + ")"

def drop(): 
    return Drop(uniform(0,1), uniform(0,1))
    
def drop2seg(d): 
    return Segment( max(d.x-d.r, 0), min(d.x+d.r,1) )
    
def take_pair(l): 
    res = []
    for i in range(len(l)): 
        for j in range(len(l)-i-1): 
            res.append([i,i+j+1])
    return res

def test_take_pairs(l): 
    p = take_pair(l)
    for k in range(len(p)): 
        x = p[k]
        i = x[0]
        j = x[1]
        print(str(l[i]) + ", " + str(l[j]))


def is_overlap(s1, s2): 
    if(s1.is_inside(s2.m1) or (s1.is_inside(s2.m2))): 
        return True
    return False
        
def fuse(s1, s2): 
    if(not is_overlap(s1, s2)): return False
    return Segment( min(s1.m1, s2.m1), max(s1.m2, s2.m2) )

def fuse_list(l): 
    if(len(l)==1): 
        print("List has 1 element [" + l[0].to_str() + "] ")
        return l
    p = take_pair(l)
    for k in range(len(p)): 
        i = p[k][0]
        j = p[k][1]
        s1 = l[i]
        s2 = l[j]
        if(is_overlap(s1,s2)): 
            s3 = fuse(s1, s2)
            print(str(i) + " [" + s1.to_str() + "] and " + str(j) + " [" + s2.to_str() + "] overlap --> Fused [" + s3.to_str() + "]")
            del l[i]
            del l[j-1]
            l.append(s3)
            return fuse_list(l)
     
	print("Minimal list of " + str(len(l)) + " elements")
    for x in l: print(x.to_str())
    return l

def is_full_coverage(l):
    if l is None: return False
    if( len(l)==1 and l[0].m1==0 and l[0].m2==1 ): return True 
    return False 
        
g_list = []
n = 0
while(not is_full_coverage(g_list)): 
    g_list.append(drop2seg(drop()))
    n += 1
    print("N=" + str(n))
    for x in g_list: 
        print(x.to_str())
    g_list=fuse_list(g_list)

print("Completed after N=" + str(n))


