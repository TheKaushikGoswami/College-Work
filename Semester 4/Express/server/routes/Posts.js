const express = require('express');
const router = express.Router();
const { Posts } = require('../models');
const { validateToken } = require('../middlewares/AuthMiddleware');

router.get('/', async (req, res) =>{
    
    const posts = await Posts.findAll();
    res.json(posts);

});

router.get('/:id', async (req, res) =>{
    
    const id = req.params.id;
    const post = await Posts.findByPk(id);
    res.json(post);

});

router.post('/', validateToken, async (req, res) =>{
    
    const post = req.body;
    await Posts.create(post);

    res.json(post);
});

router.delete('/:id', validateToken, async (req, res) =>{
    const postId = req.params.id;
    await Posts.destroy({
        where: {
            id: postId
        }
    })

    res.json("Post deleted")
});

module.exports = router;