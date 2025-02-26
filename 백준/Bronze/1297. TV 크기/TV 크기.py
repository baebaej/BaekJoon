import math

diagonal, height_ratio, width_ratio=input().split()
diagonal=int(diagonal)
height_ratio=int(height_ratio)
width_ratio=int(width_ratio)

ratio=math.sqrt((diagonal*diagonal)/(height_ratio*height_ratio+width_ratio*width_ratio))
height=int(ratio*height_ratio)
width=int(ratio*width_ratio)

print(height, width)
