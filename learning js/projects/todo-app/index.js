const todoDivContainer = document.getElementById("todo-container");
const createTodoElement = document.getElementById("create-todo");
let todo_index = parseInt(localStorage.getItem('todo_index') || '0');

function createTodoOnScreen(text, isLoading = false) {
    const todoInput = document.getElementById("todo-text-area");
    const todo_text = (todoInput.value.trim() || text).trim();

    if (!todo_text) {
        alert("Todo can't be empty");
        return;
    }

    const todoElement = document.createElement("div");
    todoElement.id = `todo-div${todo_index}`;
    todoElement.dataset.index = todo_index;

    const editTodoButton = document.createElement("button");
    editTodoButton.className = "edit-btn";
    const pencilIcon = document.createElement("i");
    pencilIcon.className = "fa fa-pencil";
    editTodoButton.appendChild(pencilIcon);

    const deleteTodoButton = document.createElement("button");
    deleteTodoButton.className = "delete-btn";
    const deleteImg = document.createElement("img");
    deleteImg.src = "images/dustbin.png";
    deleteImg.alt = "Delete";
    deleteTodoButton.appendChild(deleteImg);

    const todoTextSpan = document.createElement("span");
    todoTextSpan.className = "todo-text";
    todoTextSpan.textContent = todo_text;

    deleteTodoButton.onclick = function () {
        if (confirm("Do you want to delete this todo?")) {
            const index = todoElement.dataset.index;
            deleteFromLocalStorage(`todo-div${index}`);
            todoElement.remove();
        }
    };

    editTodoButton.onclick = function () {
        if (this.classList.contains("editing")) {
            const input = todoElement.querySelector("input");
            const newText = input.value.trim();
            if (newText) {
                todoTextSpan.textContent = newText;
                saveInLocalStorage(`todo-div${todoElement.dataset.index}`, newText);
            }
            input.remove();
            todoTextSpan.style.display = "inline";
            this.classList.remove("editing");
            pencilIcon.className = "fa fa-pencil";
            return;
        }

        const input = document.createElement("input");
        input.id = "edit-textbox";
        input.type = "text";
        input.value = todoTextSpan.textContent;
        input.style.flex = "1";

        todoTextSpan.style.display = "none";
        todoElement.insertBefore(input, todoElement.querySelector(".todo-actions"));
        input.focus();
        this.classList.add("editing");
        pencilIcon.className = "fa fa-check";
    };

    const buttonsDiv = document.createElement("div");
    buttonsDiv.className = "todo-actions";
    buttonsDiv.append(editTodoButton, deleteTodoButton);

    todoElement.append(todoTextSpan, buttonsDiv);
    todoDivContainer.append(todoElement);

    if (!isLoading) {
        todoInput.value = "";
        saveInLocalStorage(`todo-div${todo_index}`, todo_text);
        todo_index++;
        localStorage.setItem('todo_index', todo_index);
    }
}


function saveInLocalStorage(key, todo_text) {
    localStorage.setItem(key, todo_text);
    console.log("saved:", key);
}

function deleteFromLocalStorage(key) {
    localStorage.removeItem(key);
    console.log("deleted:", key);
}

function loadFromLocalStorage() {
    // Clear existing todos first
    todoDivContainer.innerHTML = '';
    todo_index = parseInt(localStorage.getItem('todo_index') || '0');
    
    for (let i = 0; i < todo_index; i++) {
        const key = `todo-div${i}`;
        const todo = localStorage.getItem(key);
        if (todo) {
            createTodoOnScreen(todo, true); // Pass isLoading = true
        }
    }
    console.log("loaded from local storage");
}
document.addEventListener('DOMContentLoaded', function() {
    loadFromLocalStorage();
    document.getElementById("create-todo-button").addEventListener("click", function() {
        createTodoOnScreen();
    });
});
