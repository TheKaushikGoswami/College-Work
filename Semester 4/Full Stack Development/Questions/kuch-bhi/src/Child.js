import { MessageContext } from "./MessageContent";
import { useContext } from "react";

export default function Child(){
    const msg = useContext(MessageContext);
    return (
        <div>
            <p>{msg}</p>
        </div>
    )
}