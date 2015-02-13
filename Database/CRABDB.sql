-- Describe CUSTOMERS
CREATE TABLE "Customers" (
    "CustomerID" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    "Name" TEXT NOT NULL,
    "CardNumber" TEXT NOT NULL,
    "Image" TEXT NOT NULL,
	"DefaultProductID" INTEGER NOT NULL
)

-- Describe ORDERS
CREATE TABLE "Orders" (
    "OrderID" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    "CustomerID" INTEGER NOT NULL,
    "ProductID" INTEGER NOT NULL,
    "Timestamp" TEXT NOT NULL DEFAULT (datetime('now','localtime'))
)

-- Describe PRODUCTS
CREATE TABLE "Products" (
    "ProductID" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    "Name" TEXT NOT NULL,
    "Image" TEXT NOT NULL,
    "Price" REAL NOT NULL
)

INSERT INTO Customers (Name, CardNumber, Image, DefaultProductID) VALUES ('Rene Holzmeier', '1234567890', 'Rene.jpg', 2)
INSERT INTO Products (Name, Image, Price) VALUES ('Kaffee (schwarz)', 'Kaffee (schwarz).jpg', 0.15)
INSERT INTO Products (Name, Image, Price) VALUES ('Kaffee (mit Milch)', 'Kaffee (mit Milch).jpg', 0.20)
INSERT INTO Orders (CustomerID, ProductID) VALUES (1, 2)