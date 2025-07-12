const express = require('express');
const router = express.Router();
const { Comments } = require('../models');
const { validateToken } = require('../middlewares/AuthMiddleware');

router.get('/:postId', async (req, res) =>{
    
    const postId = req.params.postId;
    const comments = await Comments.findAll({where : {PostId : postId}});
    res.json(comments);

});

router.post('/', validateToken, async (req, res) =>{
    
    const comment = req.body;

    if(comment.comment === ''){
        return res.json({error: 'Comment cannot be empty!'});
    }

    const username = req.user.username;
    comment.username = username;
    await Comments.create(comment);

    res.json(comment);
});

router.delete('/:commentId', validateToken, async (req, res) => {
    const comentId = req.params.commentId;
    await Comments.destroy({where : {id : comentId}});

    res.json('Deleted');
})

router.put('/:commentId', async (req, res) => {
    const commentId = req.params.commentId;
    const comment = req.body;
    const [updated] = await Comments.update(comment, {where : {id : commentId}});
    res.json(comment);
    console.log(updated);
    
})

module.exports = router;