import xlwt 
from xlwt import Workbook 
from xml.dom import minidom

# parse an xml file by name
sl = 0
mydoc = minidom.parse('default.xml')

print type(mydoc)

items = mydoc.getElementsByTagName('project')
print type(items)

# Workbook is created 
wb = Workbook() 
  
# add_sheet is used to create sheet. 
sheet1 = wb.add_sheet('Sheet 1')

# collect all item attributes from xml file 
# and write to created workbook sheet
print "All attributes:"
sheet1.write(0, 0, 'Serial Number')
sheet1.write(0, 1, 'Project Name')
sheet1.write(0, 2, 'Project Path')
sheet1.write(0, 3, 'Project groups')

for elem in items:
    sl += 1
    print "project name = ", elem.attributes['name'].value
    sheet1.write(sl, 0, sl)
    sheet1.write(sl, 1, elem.attributes['name'].value )
    try:
       print "project path = ", elem.attributes['path'].value
       sheet1.write(sl, 2, elem.attributes['path'].value )
    except:
       print "project path = ", elem.attributes['name'].value
       sheet1.write(sl, 2, elem.attributes['name'].value )
       pass
    sheet1.write(sl, 3, elem.attributes['groups'].value )

wb.save('project-data.xls')



