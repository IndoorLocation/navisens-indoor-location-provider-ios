#ifndef MOTIONDNACPP_H
#define MOTIONDNACPP_H

#include <vector>
#include <string>


struct coord
{
    coord(double _lat, double _lng):lat(_lat), lng(_lng)
    {}
    
    double lat;
    double lng;
};

struct Obj
{
    std::vector<coord> coords;
    MapObjectType type;
    std::string ID;
};

struct Map
{
    BOOL hasIndoorMap;
    BOOL hasOutdoorMap;
    BOOL isUsingMapCorrections;
    int floor;
    bool isNew;
    std::vector<Obj> objects;
};

#endif
