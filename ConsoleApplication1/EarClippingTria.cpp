#include "EarClippingTria.h"
#include <fstream>

bool EarClippingTriangulation(const char* input)
{
	std::vector <CVertex> verts;
	bool valid = GetVerticesArray(input, verts);

	if (!valid) return false;

	std::ofstream wvfile;
	wvfile.open("Triangles.obj");

	FillVertices(wvfile, verts);

	ClipEar(wvfile, verts, 0);

	wvfile.close();

	return true;
}

bool GetVerticesArray(const char* input, std::vector <CVertex>& verts)
{
	std::string vertsStr(input);
	std::string::size_type sz = 0;	

	while (sz < vertsStr.length())
	{
		CVertex vert;
		if (GetVertex(vertsStr, sz, vert) == false) return false;
		verts.push_back(vert);
    }

	if (verts.size() < 4) return false;

	return true;
}

bool GetVertex(std::string& vertsStr, std::string::size_type& sz, CVertex& vert)
{
	std::string::size_type sztmp;

	//convert from string to double for the x component of the vertex
	double x, y, z;
	try
	{
		x = std::stof(vertsStr.substr(sz), &sztmp);
	}
	catch(...)
	{
		return false;
	}
	sz += sztmp;
	if (vertsStr[sz] != ',' && sz != vertsStr.length()) return false;
	vert.x = x;
	sz++;

	//convert from string to double for the y component of the vertex
	try
	{
		y = std::stof(vertsStr.substr(sz), &sztmp);
	}
	catch (...)
	{
		return false;
	}
	sz += sztmp;
	if (vertsStr[sz] != ',' && sz != vertsStr.length()) return false;
	vert.y = y;
	sz++;

	//z component is 0
	vert.z = 0.;
	return true;
}

void FillVertices(std::ofstream& wvfile, const std::vector <CVertex>& verts)
{
	std::vector <CVertex>::const_iterator it = verts.begin();

	while (it != verts.end())
	{
		wvfile << "v " << it->x << ' ' << it->y << ' ' << it->z << std::endl;
		it++;
	}
}

void ClipEar(std::ofstream& wvfile, std::vector <CVertex>& verts, int inc)
//iterative function, inc gets incremented by 1 and one element is removed from verts vector in each iteration
{
	if (verts.size() < 3)
		return;

	wvfile << "f " << 1 << ' ' << 2+inc << ' ' << 3+inc << std::endl;

	verts.erase(verts.begin() + 1);
	inc++;

	ClipEar(wvfile, verts, inc);
}