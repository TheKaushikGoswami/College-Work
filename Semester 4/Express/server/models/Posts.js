module.exports = (sequelize, DataTypes) => {

    const Posts = sequelize.define('Posts', {
        title: {
            type: DataTypes.STRING,
            allowNull: false
        },
        content: {
            type: DataTypes.TEXT,
            allowNull: false
        },
        username: {
            type: DataTypes.STRING,
            allowNull: false
        }
    });

    Posts.associate = (models) => {
        Posts.hasMany(models.Comments, {
            onDelete: 'cascade'
        })
    }

    return Posts;
}