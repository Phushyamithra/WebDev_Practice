const Navbar = () => {
    return ( 
        <div className="navbar">
            <h1>The Dojo Blog</h1>
            <div className="links">
                <a href="/" style={
                    {
                        backgroundColor : "#e6ffe6" ,
                        borderRadius : '8px'
                    }
                }> Home</a>
                <a href="/create" style={
                    {
                        backgroundColor : "#e6ffe6" ,
                        borderRadius : '8px'
                    }
                }> New Blog </a>
            </div>
        </div>
     );
}
 
export default Navbar;
