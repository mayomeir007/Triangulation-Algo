This is a command-line application that takes an array of polygon vertices in 2D as input and outputs a wavefront file (.obj) for displaying the geometry on the screen. 

### Description
For the sake of implementation simplicity the following constraints apply:
- Convex polygons only.
- No holes.
- No self intersecting polygons

● The tool accept command line argument from user that provides sets of {x,y} 2D
(z-position is always zero) locations of at least 4 vertices, in the following format
“vx0,vy0,vx1,vy1,vx2,vy2,vx3,vy3...etc” where vx - vertex position along the x axis,vyvertex
position along the y axis. Given that, the application should be capable of
handling convex polygons with 4,5,6,8,N, where N > 3 corners.

● The generated vertices of triangles are written into a text file in wavefront (.obj)
format. https://www.fileformat.info/format/wavefrontobj/egff.htm

● Remarks for the wavefront file:
- only vertices and face data are written. UVs and normals are ignored.(See the link above
for simple .obj layout)
