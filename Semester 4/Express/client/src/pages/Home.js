import React from "react";
import axios from 'axios';
import { useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';

function Home() {

    const [allPosts, setAllPosts] = useState([]);
    const navigate = useNavigate();

    useEffect(() => {
        axios.get('http://localhost:3001/posts')
            .then((res) => {
                setAllPosts(res.data);
            })
            .catch((err) => {
                console.log(err);
            });
    }, []);

    return (

        <div>
            <div className='posts'>
                {allPosts.map((post) => {
                    return (
                        <div className='post' onClick={() => {
                            navigate('/posts/' + post.id);
                        }}>
                            <div className='title'>{post.title}</div>
                            <div className='content'>{post.content}</div>
                            <div className='author'>- {post.username}</div>
                        </div>
                    );
                })}
            </div>
        </div>
    )
}

export default Home;