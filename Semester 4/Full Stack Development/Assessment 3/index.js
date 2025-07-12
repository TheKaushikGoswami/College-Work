//  Explain the difference between res.send(), res.json(), and res.end() in Express.js.

// res.send() is used to send a response of any type. It can be a string, an object, an array, or a buffer. It automatically sets the Content-Type header based on the type of the response.

// res.json() is used to send a JSON response. It automatically sets the Content-Type header to application/json.

// res.end() is used to end the response process. It can be used to send a response with a status code and a message, but it does not set the Content-Type header automatically. It is useful when you want to manually set the response headers or when you want to send a response without any content.

// res.send() and res.json() are higher-level abstractions that handle setting the Content-Type header for you, while res.end() gives you more control over the response process.

