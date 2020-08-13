#!/usr/bin/wolfram -script
shrink[pts_List] :=
  Module[ {mid}, 
          mid = Plus@@pts / Length[pts]; 
          Map[ # + mid&, pts] / 2]
polygon = {{1,1},{3,1},{3,2}}
smallerPolygon = shrink[polygon]
Print[smallerPolygon]
g = Graphics[{RGBColor[1, 0, 0], Polygon[polygon], 
              RGBColor[0, 0, 1], Polygon[smallerPolygon]}]
Export["test.png", g, ImageSize -> {1200, 700}]
