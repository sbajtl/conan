extern "C"
{
#define REAL double
#ifndef NO_TIMER
#define NO_TIMER
#endif
#ifndef ANSI_DECLARATORS
#define ANSI_DECLARATORS
#endif
#include "triangle.h"
}

#include <iostream>
#include <cmath>
#include <cstdlib>


int main(int, char *[])
{
    triangulateio din;
    triangulateio out;

    const int nPts = 700;
    din.numberofpoints = nPts;
    din.numberofpointattributes = 0;
    din.numberofholes = 0;
    din.numberofregions = 0;

    din.pointlist = new double[nPts*2];
    for (int i = 0; i < nPts; i++) {
        din.pointlist[i*2]   =  3.0*std::cos(double(i)/double(nPts)*2.0*3.1415926) + double(std::rand()*0.5)/double(RAND_MAX);
        din.pointlist[i*2+1] = 10.0*std::sin(double(i)/double(nPts)*2.0*3.1415926) + double(std::rand()*0.5)/double(RAND_MAX);
    }

    din.numberofsegments = nPts;
    din.segmentlist = new int[nPts*2];
    din.segmentmarkerlist = NULL;
    for (int i = 0; i  <nPts; i++) {
        din.segmentlist[2*i] = (i%nPts);
        din.segmentlist[2*i+1] = ((i+1)%nPts);
    }


    din.pointattributelist = NULL;
    din.pointmarkerlist    = NULL;
    din.holelist           = NULL;
    din.regionlist         = NULL;


    out.pointlist = NULL;
    out.pointattributelist = NULL;
    out.pointmarkerlist = NULL;
    out.trianglelist =  NULL;          /* Not needed if -E switch used. */
    /* Not needed if -E switch used or number of triangle attributes is zero: */
    out.triangleattributelist =  NULL;
    out.neighborlist =  NULL;         /* Needed only if -n switch used. */
    /* Needed only if segments are output (-p or -c) and -P not used: */
    out.segmentlist =  NULL;
    /* Needed only if segments are output (-p or -c) and -P and -B not used: */
    out.segmentmarkerlist = (int *) NULL;
    out.edgelist =  NULL;             /* Needed only if -e switch used. */
    out.edgemarkerlist = NULL;   /* Needed if -e used and -B not used. */

    ::triangulate(const_cast<char*>("pzen"), &din, &out, NULL);

    std::cout << "16385\n{\nOFF # 0 0 1 1 1\n";
    std::cout << out.numberofpoints << ' ' << out.numberoftriangles << " 0\n";
    for (unsigned i = 0; i < out.numberofpoints; i++)
        std::cout << out.pointlist[i*2] << ' ' <<  out.pointlist[i*2+1] << " 0.0\n";

    for (unsigned i = 0; i < out.numberoftriangles; i++)
        std::cout << "3 " <<  out.trianglelist[i*3] << ' ' << out.trianglelist[i*3+1] << ' ' << out.trianglelist[i*3+2] << " #HHH\n";

    std::cout << "}\n";
    return 0;
}
