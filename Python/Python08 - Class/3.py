class Book(object):
    authors = [] #defaultowo wspoldzielone przez wszystkie klasy

    def __init__(self): #taki ctor
        self.authors = []

    def add_author(self, author):
        self.authors.append(author)

b_1 = Book()
b_1.add_author("Author 1")
print(b_1.authors)

b_2 = Book()
b_2.add_author("Author 2")
print(b_2.authors)