import { useState } from "react";

const Home = () => {
    const [name, setName]= useState('Mario');
    // let name ='Mario';
    const [age,setAge]=useState(25);
    // let age = 25;
    // const handleClickMe = () => {
    //     console.log('Hello masteruu !');
    // }
    // const handleClickParam = (name) =>{
    //     console.log('Hello '+name);
    // }
    const handleChangeValue= () => {
        setName('Mithra');
        setAge(23);
    }
    
    return ( 
        <div className="home">
            <div className="content">
                <h1>Home Page</h1>
                {/* <button onClick={handleClickMe} >Click me !!</button>
                <button onClick={() =>{
                    handleClickParam('Robo')
                }}>Click me to send param !!</button> */}
                <p>{ name } is { age } old</p>
                <button onClick={handleChangeValue}> Click to change name and age</button>
            </div>
        </div>
     );

}

export default Home;