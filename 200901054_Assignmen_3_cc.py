#!/usr/bin/env python
# coding: utf-8

# In[5]:


from xml.dom import minidom
import pandas as pd

# Writing to an Excel
# sheet using Python


doc = minidom.parse("compiler xml Assignment.xml")



books = doc.getElementsByTagName("book")
print(
    "Book_Id |  Author           |       Title    |       Genre        |        price     |          publish date |  "
    "Description")
data = []
for book in books:
    book_id = book.getAttribute("id")
    author = book.getElementsByTagName("author")[0]
    title = book.getElementsByTagName("title")[0]
    genre = book.getElementsByTagName("genre")[0]
    price = book.getElementsByTagName("price")[0]
    publish_date = book.getElementsByTagName("publish_date")[0]
    description = book.getElementsByTagName("description")[0]
    Book_data = {(book_id, "  | ", author.firstChild.data, "  |   ", title.firstChild.data, "  | ",
                  genre.firstChild.data, "  | ", price.firstChild.data, "  | ", publish_date.firstChild.data, " | ",
                  description.firstChild.data)}
    data.append(Book_data)
df = pd.DataFrame(data)
df.to_excel("file.xlsx", index=False)
#  sheet1.write(0,1,book_id[0])
# wb.save('xlwt excel1.xls')


# In[ ]:




