// Callback vs Promise

// Callback

function doSomething(callback) {
    setTimeout(() => {
        callback('First data from callback');
    }, 1000);
}

// Callback Hell

function doOtherThing(callback) {
    setTimeout(() => {
        callback('Second data from callback');
    }, 1000);
}

function doAll() {
    try {
        doSomething((data) => {
            var processedData = data.split('');

            try {
                doOtherThing((data) => {
                    var processedData = data.split('');

                    try {
                        setTimeout(() => {
                            console.log(processedData);
                        }, 1000);
                    } catch (err) {
                        // handle error
                    }
                });
            } catch (err) {
                // handle error
            }
        });
    } catch (err) {
        // handle error
    }
}

doAll();

// Promise

const doSomethingPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('First data from promise');
    }, 1000);
});

const doOtherThingPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('Second data from promise');
    }, 1000);
});

doSomethingPromise
    .then(data => {
        console.log(data);
        return doOtherThingPromise;
    })
    .then(data2 => console.log(data2))
    .catch(error => console.log('Ops', error));

