import xls
  
filename = "project-data.xls"
  
fields = [] 
rows = [] 
  
# Reading csv file 
with open(filename, 'r') as xlsfile: 
    # Creating a csv reader object 
    csvreader = xls.reader(csvfile) 
      
    # Extracting field names in the first row 
    fields = xlsreader.next() 
  
    # Extracting each data row one by one 
    for row in xlsreader: 
        rows.append(row)
  
# Printing out the first 5 rows 
for row in rows[:5]: 
    print(row)
