document.addEventListener("DOMContentLoaded", function() {
    const notes = [];

    // Function to create a new note
    function createNote() {
        const title = document.getElementById("note-title").value;
        const content = document.getElementById("note-content").value;

        if (title && content) {
            const note = {
                title: title,
                content: content,
            };

            notes.push(note);
            displayNotes();
            clearInputFields();
        }
    }

    // Function to display notes
    function displayNotes() {
        const notesList = document.getElementById("notes");
        notesList.innerHTML = "";

        notes.forEach((note, index) => {
            const listItem = document.createElement("li");
            listItem.innerHTML = `
                <strong>${note.title}</strong>
                <p>${note.content}</p>
                <button onclick="deleteNote(${index})">Delete</button>
                <button class="save-button" onclick="saveNoteAsPDF(${index})">Save as PDF</button>
            `;
            notesList.appendChild(listItem);
        });
    }

    // Function to delete a note
    function deleteNote(index) {
        notes.splice(index, 1);
        displayNotes();
    }

    // Function to save a note as a PDF
    function saveNoteAsPDF(index) {
        const noteToSave = notes[index];
        const doc = new jsPDF();

        // Add note title and content to the PDF
        doc.setFontSize(16);
        doc.text(noteToSave.title, 10, 10); // Title
        doc.setFontSize(12);
        doc.text(noteToSave.content, 10, 20); // Content

        // Save the PDF with a unique filename using FileSaver.js
        const fileName = `note_${index}.pdf`;
        doc.save(fileName);

        alert(`Note saved as ${fileName}`);
    }

    // Function to load notes from local storage (on page load)
    function loadNotesFromLocalStorage() {
        for (let i = 0; i < localStorage.length; i++) {
            const key = localStorage.key(i);

            if (key.startsWith("note_")) {
                const note = JSON.parse(localStorage.getItem(key));
                notes.push(note);
            }
        }

        displayNotes();
    }

    // Function to clear input fields
    function clearInputFields() {
        document.getElementById("note-title").value = "";
        document.getElementById("note-content").value = "";
    }

    // Event listener for create note button
    document.getElementById("create-note").addEventListener("click", createNote);

    // Initial display of notes and loading from local storage
    loadNotesFromLocalStorage();
});
