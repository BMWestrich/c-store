include_directories(${PROJECT_SOURCE_DIR}/include/)

add_library(common SHARED Block.cpp BlockForceContig.cpp BlockPosNonContig.cpp BlockWithPos.cpp DataSource.cpp DataSourcePosFilter.cpp DatasourceFilters.cpp DoubleValPos.cpp Exception.cpp FloatValPos.cpp IntValPos.cpp LongValPos.cpp MinicolBlock.cpp NullValPos.cpp Pair.cpp PosBlock.cpp PosBlockArray.cpp PosPair.cpp Predicate.cpp SBlock.cpp SPair.cpp StringValPos.cpp UnexpectedException.cpp UnimplementedException.cpp ValPos.cpp Writer.cpp)
