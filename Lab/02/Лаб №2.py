from flask import Flask
from flask.globals import request
import openpyxl
import os.path
from datetime import datetime



app = Flask(__name__)

file = os.path.abspath(os.path.dirname(__file__))


size_buffer = 0
buffer = []


@app.route('/', methods=['POST', 'GET'])
def index():
   global buffer
   
   if request.method == 'POST':
      
      buffer += [request.json]
      print('req.body:', buffer[-1])
      if (len(buffer) > size_buffer):
         excel()
         buffer = []
         
         
      return 'OK'
      
   elif request.method == 'GET':
      return 'Это GET запрос'


def excel():
   global buffer
   
   STORAGE_FILE = os.path.join(file, 'data.xlsx')
   
   book = None
   if not os.path.exists(STORAGE_FILE):
      book = openpyxl.Workbook()
      book.active['A1'] = 'N'
      book.active['B1'] = 'User ID'
      book.active['C1'] = 'Datetime'
      book.active['D1'] = 'Item'
      book.active['E1'] = 'Prise'
      book.save(STORAGE_FILE)
   else:
      book = openpyxl.open(STORAGE_FILE)   
   sheet = book.active
   
   max_row = len(sheet['A'])
   
   row = max_row + 1
   for dataset in buffer:
      check = dataset['check']
      for item in check:
          sheet[row][0].value = row - 1
          sheet[row][1].value = dataset['user_id']
          sheet[row][2].value = datetime.now()
          sheet[row][3].value = item['item']        
          sheet[row][4].value = item['price']
          row += 1

   book.save(STORAGE_FILE)
   book.close()

if __name__ == '__main__':
   app.run()
