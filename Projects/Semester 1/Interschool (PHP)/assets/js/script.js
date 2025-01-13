function generateParticipants() {

    var numParticipants = document.getElementById("no_of_participants").value;
    var participantFields = document.getElementById("participantFields");

    participantFields.appendChild(document.createElement("br"));
    participantFields.innerHTML = "";
    for (var i = 1; i <= numParticipants; i++) {

        var name = document.createElement("input");
        name.type = "text";
        name.name = "participant_" + i + "_name";
        name.id = "participant_" + i + "_name";
        name.placeholder = " Name";
        name.class = "form-control";
        name.required = true;

        var clas = document.createElement("input");
        clas.type = "text";
        clas.name = "participant_" + i + "_class";
        clas.id = "participant_" + i + "_class";
        clas.placeholder = " Class";
        clas.class = "form-control";
        clas.required = true;

        var roll = document.createElement("input");
        roll.type = "number";
        roll.name = "participant_" + i + "_roll";
        roll.id = "participant_" + i + "_roll";
        roll.placeholder = " Roll Number";
        roll.class = "form-control";
        roll.required = true;

        var contact = document.createElement("input");
        contact.type = "number";
        contact.name = "participant_" + i + "_contact";
        contact.id = "participant_" + i + "_contact";
        contact.placeholder = " Contact Number";
        contact.class = "form-control";
        contact.required = true;

        participantFields.appendChild(document.createElement("br"));
        participantFields.appendChild(document.createTextNode("Participant " + i + ": "));
        participantFields.appendChild(name);
        participantFields.appendChild(clas);
        participantFields.appendChild(roll);
        participantFields.appendChild(contact);
        participantFields.appendChild(document.createElement("br"));
        participantFields.appendChild(document.createElement("br"));
    }
}

function generateTeachers() {

    var numTeachers = document.getElementById("no_of_teachers").value;
    var teacherFields = document.getElementById("teacherFields");
    teacherFields.innerHTML = "";
    teacherFields.appendChild(document.createElement("br"));

    for (var i = 1; i <= numTeachers; i++) {

        var name = document.createElement("input");
        name.type = "text";
        name.name = "teacher_" + i + "_name";
        name.id = "teacher_" + i + "_name";
        name.placeholder = " Name";
        name.class = "form-control";
        name.required = true;

        var contact = document.createElement("input");
        contact.type = "number";
        contact.name = "teacher_" + i + "_contact";
        contact.id = "teacher_" + i + "_contact";
        contact.placeholder = " Contact Number";
        contact.class = "form-control";
        contact.required = true;

        var email = document.createElement("input");
        email.type = "email";
        email.name = "teacher_" + i + "_email";
        email.id = "teacher_" + i + "_email";
        email.placeholder = " Email ID";
        email.class = "form-control";
        email.required = true;

        teacherFields.appendChild(document.createTextNode("Teacher " + i + ": "));
        teacherFields.appendChild(name);
        teacherFields.appendChild(contact);
        teacherFields.appendChild(email);
        teacherFields.appendChild(document.createElement("br"));
        teacherFields.appendChild(document.createElement("br"));
    }
}

function generateOptions() {

    var numParticipantsField = document.getElementById("no_of_participants");
    var eventType = document.getElementById("event_type").value;
    numParticipantsField.innerHTML = "";

    if (eventType == "DC") {
        var numParticipants = document.createElement("option");
        numParticipants.value = "default";
        numParticipants.innerHTML = "---";
        numParticipants.selected = true;
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "1";
        numParticipants.innerHTML = "1";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "2";
        numParticipants.innerHTML = "2";
        numParticipantsField.appendChild(numParticipants);


    }
    else if (eventType == "S") {
        var numParticipants = document.createElement("option");
        numParticipants.value = "default";
        numParticipants.innerHTML = "---";
        numParticipants.selected = true;
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "6";
        numParticipants.innerHTML = "6";
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "7";
        numParticipants.innerHTML = "7";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "8";
        numParticipants.innerHTML = "8";
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "9";
        numParticipants.innerHTML = "9";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "10";
        numParticipants.innerHTML = "10";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "11";
        numParticipants.innerHTML = "11";
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "12";
        numParticipants.innerHTML = "12";
        numParticipantsField.appendChild(numParticipants);
    }

    else if (eventType == "D") {
        var numParticipants = document.createElement("option");
        numParticipants.value = "default";
        numParticipants.innerHTML = "---";
        numParticipants.selected = true;
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "8";
        numParticipants.innerHTML = "8";
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "9";
        numParticipants.innerHTML = "9";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "10";
        numParticipants.innerHTML = "10";
        numParticipantsField.appendChild(numParticipants);


        var numParticipants = document.createElement("option");
        numParticipants.value = "11";
        numParticipants.innerHTML = "11";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "12";
        numParticipants.innerHTML = "12";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "13";
        numParticipants.innerHTML = "13";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "14";
        numParticipants.innerHTML = "14";
        numParticipantsField.appendChild(numParticipants);

        var numParticipants = document.createElement("option");
        numParticipants.value = "15";
        numParticipants.innerHTML = "15";
        numParticipantsField.appendChild(numParticipants);
    }
}