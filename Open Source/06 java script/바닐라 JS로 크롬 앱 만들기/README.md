# Cloning a Productivity App with VanillaJS

**JS-Basics Nomad Academy Course.**
[link](https://nomadcoders.co/javascript-for-beginners/lobby)
image 출처: [unsplash](https://unsplash.com/)

## 알게 된 것 정리
```javascript
document.querySelector(""); // getelementbyid 등
/* local storage 이용하기 */
localStorage.setItem("currentUser", name); 
localStorage.getItem("currentUser");

form.classList.add("")
form.classList.remove("")
`${hours < 10 ? `0${hours}` : hours}`
setInterval(getTime, 1000);
body.prepend(image);
Math.floor(Math.random() * IMG_NUMBER) // js 내장 객체 Math

event.target.parentNode // 이벤트 응답결과보다 더 구체적인 정보는 target object에서 제공
clockTitle.innerText // 태그 안 텍스트
toDoInput.value // input의 내용

JSON.stringify(toDos) // localstrorage에 담을 수 있도록 String 으로 변환
JSON.parse(loadedToDos) // JSON으로 변환

delBtn.addEventListener("click", deleteToDo) // EventListener("동작", 함수이름)
parsedToDos.forEach(function(toDo) {
      paintToDo(toDo.text);
    });

li = document.createElement("li"); // li 엘리먼트 생성
li.appendChild(delBtn); // 자식 요소 추가
li.id = newId; // <li id="1"> </li>

const cleanToDos = toDos.filter(function(toDo) {
    return toDo.id !== parseInt(li.id);
  });

배열.filter()
배열.push()
배열.length
배열.forEach()
```

로드 시, localStorage 에 있는 toDos 키에 값이 담겨있으면 하나씩 가져와서 순서대로 태그의 id와 localStorage의 toDos에 1부터 다시 부여함(그래서 같은 숫자임).