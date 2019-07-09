import math

def mmm(x1,y1,potato1,x2,y2,potato2):
    """return turn values and distance

    >>> mmm(0,0,0, 3,4,180)
    (36.87, 5.0, 143.13)

    >>> mmm(0,0,0, 0,1,0)
    (0, 1.0, 0)
    """
    
    x3 = x2 - x1
    y3 = y2 - y1
    

    if(x3 == 0):
        turn1 = 0
    else:
        turn1 =  round(90 - math.degrees(math.atan(y3/x3)),3)
        
    dist = math.sqrt((x3**2)+(y3**2))
    turn2 = potato2 - (potato1 + turn1)
    #print(turn1)
    return turn1, dist, turn2
        


if __name__ == "__main__":
    import doctest
    doctest.testmod()
