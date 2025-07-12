import Child from "./Child";

export default function Parent( {msg} ) {
  return (
    <div>
      <Child msg={msg} />
    </div>
  )
}
