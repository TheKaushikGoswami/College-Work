// 1.	Explain the differences between map(), filter(), and reduce() with respect to their return values and performance.

// map() returns a new array with the same length as the original array, where each element is the result of applying a function to the corresponding element of the original array. It does not modify the original array.

// filter() returns a new array with elements that pass the test implemented by the provided function. It does not modify the original array.

// reduce() applies a function against an accumulator and each element in the array (from left to right) to reduce it to a single value. It returns the final value of the accumulator. It does not modify the original array.

// In terms of performance, map() and filter() are generally faster than reduce() because they do not require maintaining an accumulator value. However, the performance difference may vary depending on the specific use case and the size of the array.



// 2. Evaluate how different HTTP methods affect data manipulation in a RESTful API

// In a RESTful API, different HTTP methods (GET, POST, PUT, DELETE) are used to perform different operations on resources. Each method has a specific purpose and affects data manipulation in the following ways:

// - GET: Used to retrieve data from a server. It should not have any side effects on the data and should be idempotent (repeated requests should have the same result). It is commonly used to fetch resources or collections of resources.

// - POST: Used to create a new resource on the server. It typically involves sending data to the server to be processed and stored. It is not idempotent, meaning multiple identical requests may have different effects.

// - PUT: Used to update an existing resource on the server. It typically involves sending data to replace the current state of the resource. It is idempotent, meaning multiple identical requests will have the same effect as a single request.

// - DELETE: Used to remove a resource from the server. It is idempotent, meaning multiple identical requests will have the same effect as a single request.

// By using these HTTP methods appropriately in a RESTful API, developers can perform various data manipulation operations such as retrieving, creating, updating, and deleting resources in a standardized and efficient manner.



// 3. Assess the implications of using status codes for error handling in APIs.

// Using status codes for error handling in APIs has several implications:

// - Standardization: Status codes provide a standardized way to communicate the outcome of an API request. Clients can interpret the status code to determine the success or failure of the request.

// - Error Identification: Different status codes represent different types of errors, such as client errors (4xx) and server errors (5xx). This allows clients to identify the nature of the error and take appropriate action.

// - Error Recovery: Status codes can provide information on how to recover from errors, such as retrying the request, providing additional information, or redirecting to a different endpoint.

// - Security: Proper use of status codes can help prevent security vulnerabilities, such as information disclosure or unauthorized access. For example, using 401 Unauthorized for authentication errors can help protect sensitive data.

// - User Experience: Status codes can impact the user experience by providing clear feedback on the outcome of a request. For example, using 404 Not Found for missing resources can help users understand why a request failed.

// Overall, using status codes for error handling in APIs can improve the reliability, security, and usability of the API by providing clear and consistent feedback to clients.



// 4. Should we always use async/await over Promises? Justify your answer with examples.

// async/await is built on Promises and makes asynchronous code easier to read and write. While it simplifies code, there are cases where Promises might be more suitable. Consider the following:

// - async/await is more readable and easier to understand, especially for developers who are new to asynchronous programming. It allows for sequential code execution and error handling using try/catch blocks.

// - Promises offer more flexibility and control over asynchronous operations, such as handling multiple asynchronous operations concurrently or conditionally chaining promises.

// - async/await can simplify error handling by allowing synchronous-style error handling with try/catch blocks. However, Promises also provide error handling through the .catch() method.

// - async/await can lead to cleaner and more maintainable code, especially for complex asynchronous operations that involve multiple asynchronous calls.

// - Promises are more suitable for scenarios where fine-grained control over asynchronous operations is required, such as

// - async/await is generally preferred for most asynchronous operations due to its readability and ease of use. However, there may be cases where using Promises directly is more appropriate, such as when dealing with complex asynchronous logic or performance-critical code.

// Example using async/await:

async function fetchData() {
    try {
        const response = await fetch('https://api.example.com/data');
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error fetching data:', error);
        return null;
    }
}

// Example using Promises:

function fetchData() {
    return fetch('https://api.example.com/data')
        .then(response => response.json())
        .catch(error => {
            console.error('Error fetching data:', error);
            return null;
        });
}



// 5. Examine the impact of port number effect on an express app

// The port number has a significant impact on an Express app, as it determines the network port on which the app will listen for incoming requests. Some key impacts of the port number on an Express app include:

// - Network Accessibility: The port number determines the network interface and port on which the Express app will be accessible. By default, Express apps listen on port 3000, but this can be configured to any available port number.

// - Security: Using non-standard port numbers can help improve security by reducing the likelihood of automated attacks targeting common ports like 80 (HTTP) or 443 (HTTPS). However, using non-standard ports may also require additional configuration for firewalls and network security.

// - Port Conflicts: If multiple applications are running on the same server, conflicts can occur if they attempt to listen on the same port number. Choosing unique port numbers for each application can help avoid conflicts and ensure that each app is accessible.

// - Environment Configuration: The port number can be configured based on the environment (development, staging, production) to ensure consistency and compatibility across different deployment environments.

// - Load Balancing: When deploying an Express app in a load-balanced environment, the port number can be used to distribute incoming requests across multiple instances of the app running on different servers.

// - Proxy Servers: Port numbers are often used in conjunction with proxy servers to route incoming requests to the appropriate backend server based on the port number specified in the request.

// Overall, the port number plays a crucial role in determining how an Express app is accessed, secured, and managed in various deployment scenarios.



// 6. Explain the concept of promises and elaborate on what problem it solves.

// Promises are objects that represent the eventual completion (or failure) of an asynchronous operation and its resulting value. They provide a way to handle asynchronous code in a more readable and manageable manner. Promises solve the problem of callback hell and improve the readability and maintainability of asynchronous code.

// The main problems that promises solve include:

// - Callback Hell: Promises help avoid nested callbacks and improve code readability by allowing asynchronous operations to be chained sequentially. This makes it easier to understand the flow of asynchronous code and handle errors more effectively.

// - Error Handling: Promises provide a standardized way to handle errors in asynchronous operations using the .catch() method. This allows errors to be propagated down the promise chain and caught at a higher level, simplifying error handling.

// - Asynchronous Control Flow: Promises allow for more control over the flow of asynchronous operations, such as chaining multiple asynchronous calls, waiting for all promises to resolve, or handling errors in a consistent manner.

// - Synchronization: Promises provide a way to synchronize asynchronous operations and ensure that code executes in the correct order, even when dealing with multiple asynchronous tasks.

// - Composition: Promises can be composed together to create complex asynchronous workflows, such as parallel execution, sequential execution, or error handling.

// Overall, promises provide a cleaner and more structured way to work with asynchronous code, making it easier to manage complex asynchronous operations and handle errors effectively.



// 7. Implement your own filter method.

Array.prototype.myFilter = function (callback) {
    const filteredArray = [];
    for (let i = 0; i < this.length; i++) {
        if (callback(this[i], i, this)) {
            filteredArray.push(this[i]);
        }
    }
    return filteredArray;
}

const numbers = [1, 2, 3, 4, 5];
const filteredNumbers = numbers.myFilter(num => num % 2 === 0);
console.log(filteredNumbers);



// 8. When should you use filter() v/s reduce() ?

// - Use filter() when you want to create a new array with elements that pass a certain condition or test. filter() is ideal for selecting elements from an array based on a specific criteria.

// - Use reduce() when you want to transform an array into a single value by applying a function to each element and accumulating the result. reduce() is useful for calculating totals, averages, or other aggregate values from an array.

// In general, filter() is used for selecting elements, while reduce() is used for transforming and aggregating elements in an array.



// 9. Considering mongoose package, write schema to add product to MongoDB database and how to update a particular product by ID.

// Schema to add a product to MongoDB database using Mongoose:

const mongoose = require('mongoose');
const Schema = mongoose.Schema;

const productSchema = new Schema({
    name: String,
    price: Number,
    category: String
});

const Product = mongoose.model('Product', productSchema);

// To add a product to the database:

const newProduct = new Product({
    name: 'Example Product',
    price: 10,
    category: 'Example Category'
});

newProduct.save()
    .then(product => {
        console.log('Product added:', product);
    }
)
    .catch(error => {
        console.error('Error adding product:', error);
    }
);

// To update a particular product by ID:

const productId = '1234567890'; // Example product ID
const updateData = {
    price: 20,
    category: 'Updated Category'
};

Product.findByIdAndUpdate(productId, updateData, { new: true })
    .then(updatedProduct => {
        console.log('Product updated:', updatedProduct);
    }
)
    .catch(error => {
        console.error('Error updating product:', error);
    }
);

// This code snippet demonstrates how to define a schema for a product, add a new product to the database, and update an existing product by its ID using Mongoose.