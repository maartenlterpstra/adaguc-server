HELPERCLASSES= ../hclasses
HELPOBJECTS = $(HELPERCLASSES)/hclasses.a

CCDFDATAMODEL = ../CCDFDataModel
CCDFDATAMODELOBJ = $(CCDFDATAMODEL)/CCDFDataModel.a

# ADAGUCSERVER = ../adagucserverEC
# ADAGUCSERVER = $(ADAGUCSERVER)/CCDFDataModel.a

#CDataReader.o COGCDims.o CImageWarper.o CGeoParams.o CCairoPlotter.o CDrawImage.o CServerError.o CRequest.o  CXMLGen.o CServerParams.o CGDALDataWriter.o CImageDataWriter.o CXMLSerializerInterface.o CDataSource.o CStopWatch.o CImgWarpBilinear.o CImgWarpBoolean.o CImgWarpNearestNeighbour.o CImgWarpNearestRGBA.o CPGSQLDB.o CDBFileScanner.o CDFObjectStore.o CDrawAA.o CFillTriangle.o CConvertASCAT.o CConvertADAGUCVector.o CConvertADAGUCPoint.o CImgRenderPoints.o CCache.o CConvertCurvilinear.o

INCLUDEDIR= $(CPPFLAGS) -I $(HELPERCLASSES) -I $(CCDFDATAMODEL) -I/usr/include/libxml2/  -I/usr/include/udunits2/ -I/usr/include/freetype2/ -I/usr/include/postgresql/ -I/usr/include/cairo/ -I/usr/include/gdal/



CCOMPILER=g++ -Wall $(INCLUDEDIR) 

#optimalization options:
#CCOMPILER=g++ -march=pentium4 -mtune=pentium4 -msse -msse2 -msse3 -mssse3 -mfpmath=sse -O2 $(INCLUDEDIR) 
CCOMPILER=g++ -march=core2 -mtune=core2 -msse -msse2 -msse3 -mssse3 -mfpmath=sse -O2 $(INCLUDEDIR) 
#CCOMPILER=g++ -O2 $(INCLUDEDIR)
#CCOMPILER=g++ -march=k8-sse3 -mtune=k8-sse3 -msse -msse2 -msse3 -mssse3 -mfpmath=sse -O2 $(INCLUDEDIR)  

USERLIBS=  -lhdf5 -lhdf5_hl -lnetcdf -lxml2 -lgd -lproj -lpq -ludunits2 -lfreetype -lgd -lpng -lpthread -lcurl
# -lgdal -lrt -lcairo 

# -lhdf5 -lhdf5_hl -lnetcdf -lxml2 -lgd -lproj -lpq -ludunits2 -lfreetype -lgd -lpng -lpthread -lcurl -lgdal -lcairo -lrt

# all libs together
LIBS = $(USERLIBS) $(LDFLAGS) -L$(INSTALLDIR2)/lib  
#-L/usr/lib64

OBJECTS = ../adagucserverEC/CInspire.o

EXECUTABLE= inspire

default: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS) $(EXECUTABLE).o 
	g++ $(EXECUTABLE).o $(OBJECTS) $(HELPOBJECTS) $(CCDFDATAMODELOBJ) -o  $(EXECUTABLE) $(LIBS)


%.o: %.cpp
	$(CCOMPILER) -c $< -o $@  -DENABLE_CURL

clean:
	rm $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE).o 
run:
	make
	./$(EXECUTABLE)		
