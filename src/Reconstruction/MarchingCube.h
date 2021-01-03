#ifndef DRAGON_MARCHING_CUBE_H
#define DRAGON_MARCHING_CUBE_H
#include "Geometry/TriangleMesh/TriangleMesh.h"
#include "TSDFVoxel.h"
#include <map>
namespace dragon
{
namespace reconstruction
{
    
    geometry::Point3 InterpolateEdgeVetex(const geometry::Point3 &corner1, const geometry::Point3 &corner2, float sdf1, float sdf2);

    int DetermineCase(const std::vector<TSDFVoxel > &corner_sdf);

    void MarchingCube(const geometry::Point3List &corners, const std::vector<TSDFVoxel> &corner_sdf, geometry::TriangleMesh &mesh);
}
}
#endif