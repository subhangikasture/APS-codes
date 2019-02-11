# -*- coding: utf-8 -*-
"""
Created on Thu Jun 08 06:32:25 2017

@author: user
"""
import xlrd
import numpy as np

ExcelFileName= 'example2.xlsx'
workbook = xlrd.open_workbook(ExcelFileName)
worksheet = workbook.sheet_by_name("Sheet1") # We need to read the data 
#from the Excel sheet named "Sheet1"

	
num_rows = worksheet.nrows  #Number of Rows
num_cols = worksheet.ncols  #Number of Columns

result_data =[]
for curr_row in range(0, num_rows, 1):
    row_data = []
 
    for curr_col in range(0, num_cols, 1):
        data = worksheet.cell_value(curr_row, curr_col) # Read the data in the current cell
        #print(data)
        row_data.append(data)
 
    result_data.append(row_data)
result_data = np.array(result_data)
def column(matrix, i):
    return [row[i] for row in matrix]

x = column(result_data,0)
y = column(result_data,1)
#x = [1,2,3,4,5]
#y = [2,3,4,5,6]
xlen = len(x)
x1 = np.ones(xlen)
xa = np.concatenate((x1, x))
xa = np.reshape(xa,(2,xlen))
xa = np.transpose(xa)
ya = np.transpose(y)
xt = np.transpose(xa)
x1 = np.dot(xt,xa)
x2 = np.linalg.inv(x1)
x3 = np.dot(xt,ya)
x4 = np.dot(x2,x3)
print "Training complete..."
xnew = input("Enter value of x ")
ynew = x4[0]+x4[1]*xnew
print "The Predicted value of y is ", ynew