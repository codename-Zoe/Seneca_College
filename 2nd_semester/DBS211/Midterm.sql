-- Question 1 --
CREATE TABLE inventory(
    product_id NUMBER,
    product_name VARCHAR2(100) NOT NULL,
    last_procured DATE NOT NULL,
    stock_quantity NUMBER(3,2) DEFAULT 1,
    cost_per_price NUMBER(5,2),
    perishable CHAR(1) CHECK(perishable IN ('Y','N')),
    CONSTRAINT PK_product_id PRIMARY KEY (product_id)
    );

-- Question 2 --
CREATE TABLE invoices(
    invoice_number VARCHAR2(20),
    product_id NUMBER,
    quantity_sold NUMBER(3,0) DEFAULT 1,
    rate NUMBER(5,2) NOT NULL,
    payment_type VARCHAR2(30),
    CONSTRAINT PK_invoice_number PRIMARY KEY (invoice_number),
    CONSTRAINT FK_product_id FOREIGN KEY (product_id) REFERENCES inventory (product_id),
    CONSTRAINT quantity_sold CHECK(quantity_sold > 0)
    );
    
-- Question 3 --
CREATE VIEW vw_inventory_invoices AS
SELECT iv.invoice_number,
       ivt.product_id,
       ivt.product_name,
       TO_CHAR(ivt.last_procured, 'weekday, DD Mon, YYYY') AS last_procured,
       ivt.cost_per_price + iv.quantity_sold AS total_cost_price,
       iv.rate + iv.quantity_sold AS total_selling_price
FROM invoices iv JOIN inventory ivt
ON iv.product_id = ivt.product_id
WHERE ivt.cost_per_price IS NOT NULL
ORDER BY 1;