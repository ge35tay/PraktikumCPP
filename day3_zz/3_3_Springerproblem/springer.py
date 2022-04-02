from unittest.result import failfast


start = (0,0)
fail_set = set()

path = []

def recursion(x, y,grid_set):
    
    if(len(grid_set) == 0):
        return [(x,y)]
    if(((x,y),grid_set)) in fail_set:
        return False
    
    
    
    # 1 2 
    if(((x+1,y+2) in grid_set) and recursion(x+1, y+2,grid_set)!=False):
        grid_set.remove((x+1,y+2))
        return recursion(x+1,y+2,grid_set).append((x,y))
         
    # 1 -2 
    if(((x+1,y-2) in grid_set) and recursion(x+1, y-2,grid_set)!=False):
        grid_set.remove((x+1,y-2))
        return recursion(x+1,y-2,grid_set).append((x,y))
    # -1 2
    if(((x-1,y+2) in grid_set) and recursion(x-1, y+2,grid_set)!=False):
        grid_set.remove((x-1,y+2))
        return recursion(x-1,y+2,grid_set).append((x,y))
        
    # -1 -2
    if(((x-1,y-2) in grid_set) and recursion(x-1, y-2,grid_set)!=False):
        grid_set.remove((x-1,y-2))
        return recursion(x-1,y-2,grid_set).append((x,y))

    #  2 1
    if(((x+2,y+1) in grid_set) and recursion(x+2, y+1,grid_set)!=False):
        grid_set.remove((x+2,y+1))
        return recursion(x+2,y+1,grid_set).append((x,y))

    #  2 -1
    if(((x+2,y-1) in grid_set) and recursion(x+2, y-1,grid_set)!=False):
        grid_set.remove((x+2,y-1))
        return recursion(x+2,y-1,grid_set).append((x,y))

    #  -2 1
    if(((x-2,y+1) in grid_set) and recursion(x-2, y+1,grid_set)!=False):
        grid_set.remove((x-2,y+1))
        return recursion(x-2,y+1,grid_set).append((x,y))

    #  -2 -1
    if(((x-2,y-1) in grid_set) and recursion(x-2, y-1,grid_set)!=False):
        grid_set.remove((x-2,y-1))
        return recursion(x-2,y-1,grid_set).append((x,y))


    
    fail_set.add(((x,y),grid_set))
    return False