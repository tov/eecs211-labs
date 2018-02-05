add_library(graphics
        graphics.h
        geometry/affinity.h
        geometry/bbox.h
        geometry/posn.h
        raster/bmp_header.cpp
        raster/bmp_header.h
        raster/color32.cpp
        raster/color32.h
        raster/raster.cpp
        raster/raster.h
        color_blender.cpp
        color_blender.h
        color.cpp
        color.h
        sample.h
        )
set_property(TARGET graphics PROPERTY CXX_STANDARD 14)
set_property(TARGET graphics PROPERTY CXX_STANDARD_REQUIRED On)
