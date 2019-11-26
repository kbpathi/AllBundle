from xml.dom import minidom

# parse an xml file by name
mydoc = minidom.parse('default.xml')


items = mydoc.getElementsByTagName('project')

# one specific item attribute
print('Item #2 attribute:')
print(items[1].attributes['name'].value)
try:
   print(items[1].attributes['path'].value)
except:
    print(items[1].attributes['name'].value)
    pass


# all item attributes
print "All attributes:"
for elem in items:
    print "project name = ", elem.attributes['name'].value
    try:
       print "project path = ", elem.attributes['path'].value
    except:
       print "project path = ", elem.attributes['name'].value
       pass


# one specific item's data
print('\nprinting child node data:')
try:
   print(items[11].firstChild.data)
   print(items[11].childNodes[0].data)
except:
   print "no attributes or child node data"
   pass 

'''
# all items data
print('\nAll item data:')
for elem in items:
    print(elem.firstChild.data)'''
