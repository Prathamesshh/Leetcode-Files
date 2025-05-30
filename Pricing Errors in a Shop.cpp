/*A shop uses old-style cash registers where prices are entered manually instead of being scanned from a database. This manual process can sometimes lead to errors.

Given:

A list of product names and their correct prices.
A list of products that were sold along with the price entered during checkout.
Task:
Compare the entered prices with the correct prices and determine the number of errors.

Input Format
An array products[] where each element is a string representing a product name.
An array productPrices[] where each element is a double representing the correct price of the corresponding product in products[].
An array productSold[] where each element is a string representing a product sold.
An array soldPrice[] where each element is a double representing the price entered during checkout for the corresponding product in productSold[].
Output Format
An integer representing the number of errors in pricing.


products = ["eggs", "milk", "cheese"];
productPrices = [2.89, 3.29, 5.79];

productSold = ["eggs", "eggs", "cheese", "milk"];
soldPrice = [2.89, 2.99, 5.97, 3.29];
*/



int priceCheck(vector<string> products, vector<float> productPrices, vector<string> productSold, vector<float> soldPrice) {
    unordered_map<string, double> pricemap;
        for(int i=0;i<products.size();i++){
            pricemap[products[i]] = productPrices[i];
        }
        int errors_count =0;
        for(int i=0;i<productSold.size();i++){
          if(pricemap[productSold[i]]!=soldPrice[i]) errors_count++;  
        }
        
        return errors_count;
}
