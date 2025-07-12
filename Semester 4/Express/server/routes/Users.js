const express = require('express');
const router = express.Router();
const { Users } = require('../models');
const brcypt = require('bcrypt');
const { sign } = require('jsonwebtoken');
const { validateToken } = require('../middlewares/AuthMiddleware');

router.get('/', validateToken, async (req, res) => {
    res.json(req.user);
});

router.post('/register', async (req, res) => {
    const { username, password } = req.body;
    const user = await Users.findOne({ where: { username } });
    if (user) {
        return res.json({ error: 'Username already exists' });
    }
    brcypt.hash(password, 10).then((hash) => {
        Users.create({
            username,
            password: hash
        });
        res.json({ message: 'User created' });
    });
    
});

router.post('/login', async (req, res) => {
    const { username, password } = req.body;
    const user = await Users.findOne({ where: { username: username } });
    if (!user) {
        return res.json({ error: 'Invalid username or password' });
    }

    brcypt.compare(password, user.password).then((match) => {
        if (!match) {
            return res.json({ error: 'Wrong username & password combination' });
        }

        const accessToken = sign({username: user.username, id: user.id}, "importantsecret");
        res.json({token: accessToken, username: user.username, id: user.id });
    });
});

module.exports = router;