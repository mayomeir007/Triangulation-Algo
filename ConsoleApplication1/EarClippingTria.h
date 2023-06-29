#pragma once
#include <vector>
#include <string>

//structure for a vertex in 3D
typedef struct CVertex
{
	double x;
	double y;
	double z;
}CVertex;

//main method. Outputs wavefront obj file named 'Triangles.obj' in the directory of the .exe file
bool EarClippingTriangulation(const char* input);

//auxiliary functions
//processes the command line input string and returns array of vertices 
bool GetVerticesArray(const char* input, std::vector <CVertex>& verts);

//return a Cvertex using the input string and location in the string from which to convert to doubles
bool GetVertex(std::string& vertsStr, std::string::size_type& sz, CVertex& vert);

//writes to the obj file all the vertices in 3D
void FillVertices(std::ofstream& wvfile, const std::vector <CVertex>& verts);

//writes to the obj file all the faces
void ClipEar(std::ofstream& wvfile, std::vector <CVertex>& verts, int inc);