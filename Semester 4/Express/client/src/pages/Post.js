import React, { useEffect, useState, useContext } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import axios from 'axios';
import { AuthContext } from '../helpers/AuthContext';

function Post() {
    const navigate = useNavigate();
    let { id } = useParams();
    const [post, setPost] = useState({});
    const [comments, setComments] = useState([]);
    const [comment, setComment] = useState('');
    const { authState } = useContext(AuthContext);

    useEffect(() => {
        axios.get('http://localhost:3001/posts/' + id).then((res) => {
            setPost(res.data);
        });

        axios.get('http://localhost:3001/comments/' + id).then((res) => {
            setComments(res.data);
        });
    }, [id]);

    const deleteComment = (commentId) => {
        axios.delete('http://localhost:3001/comments/' + commentId, {
            headers: {
                accessToken: localStorage.getItem('accessToken')
            }
        }).then((res) => {
            if(res.data.error){
                alert(res.data.error);
            }
            else{
                setComments(comments.filter((val) => {
                    return val.id !== commentId;
                }));
            }
        });
    }

    const addComment = () => {
        axios.post('http://localhost:3001/comments',
            {
                comment: comment,
                PostId: id
            },
            {
                headers:
                {
                    accessToken: localStorage.getItem('accessToken')
                }
            }

        ).then((res) => {
            if (res.data.error) {
                alert(res.data.error);
            }
            else {
                const newComment = { comment: comment, username: res.data.username };
                setComments([...comments, newComment]);
                setComment('');
            }
        });
    }

    const deletePost = (postId) => {
        axios.delete('http://localhost:3001/posts/' + postId, {
            headers: {
                accessToken : localStorage.getItem('accessToken')
            }
        })
    .then((res) => {
        if (res.data.error) {
            alert(res.data.error);
        }
        else{
            navigate('/')
        }
    })
    }

    return (
        <div>
            <div className='postPage'>
                <div className='postitem'>
                    <div className='postContent'>

                    <div className='title'>{post.title}</div>
                    <div className='content'>{post.content}</div>
                    <div className='author'>- {post.username}</div>
                    </div>
                    {
                        authState.status && authState.username === post.username && <div className='post-delete'>
                            <button className='delete delete-post' onClick={() => {deletePost(post.id)}}>Delete Post</button></div>
                    }
                </div>
                <div className='comments'>
                    <div className='addComment'>
                        <input type='text' placeholder='Add a comment' value={comment} onChange={(event) => {
                            setComment(event.target.value);
                        }} />
                        <button onClick={addComment}>Submit</button>
                    </div>
                    <div className='commentList'>
                        {
                            comments.map((comment) => {
                                return (
                                    <div className='comment-row' key={comment.id}>
                                        <div className='comment'>
                                            <div className='comment-content'>{comment.comment}</div>
                                            <div className='comment-author'>- {comment.username}</div>
                                        </div>
                                        {authState.username === comment.username && <button className='delete' onClick={() => deleteComment(comment.id)}>X</button>}
                                    </div>
                                )
                            })
                        }
                    </div>
                </div>
            </div>
        </div>
    )
}

export default Post
