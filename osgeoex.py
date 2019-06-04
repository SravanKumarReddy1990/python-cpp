from osgeo import ogr, osr
from shapely.geometry import Point, Polygon
from shapely.wkb import loads
import json

driver = ogr.GetDriverByName('ESRI Shapefile')
polyshp = driver.Open('./mapping-india/apshapefiles/ap_abl.shp')
polylyr = polyshp.GetLayer(0)
#driver.ImportFromEPSG(4326)
for feature in polylyr:
    point = Point(78.158560,16.506876)
    geomPolygon = loads(feature.GetGeometryRef().ExportToWkb())
    if geomPolygon.contains(point) :
#        print (geomPolygon.contains(point))
        print (feature["BEAT"])
#        print (geomPolygon)

