use orderDB;
select book.title, orders.quantity from book, orders where book.id = orders.book_id and orders.quantity > 8;
quit
