class Book(object):
    title = "Title of the book"

    def print_title(self):
        print(self.title)

book = Book()
book.print_title()
Book.print_title(book)