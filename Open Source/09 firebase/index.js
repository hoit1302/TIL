// Import stylesheets
import "./style.css";
// Firebase App (the core Firebase SDK) is always required and must be listed first
import * as firebase from "firebase/app";

// Add the Firebase products that you want to use
import "firebase/auth";
import "firebase/firestore";

import * as firebaseui from "firebaseui";

// Document elements
const startRsvpButton = document.getElementById("startRsvp");
const guestbookContainer = document.getElementById("guestbook-container");

const form = document.getElementById("leave-message");
const input = document.getElementById("message");
const guestbook = document.getElementById("guestbook");
const numberAttending = document.getElementById("number-attending");
const rsvpYes = document.getElementById("rsvp-yes");
const rsvpNo = document.getElementById("rsvp-no");

var rsvpListener = null;
var guestbookListener = null;

async function main() {
  // Add Firebase project configuration object here
  var firebaseConfig = {
    apiKey: "AIzaSyDRHFTffvKsZCeA78z_P5poETosHiGJYvY",
    authDomain: "fir-web-codelab-d48d5.firebaseapp.com",
    databaseURL: "https://fir-web-codelab-d48d5.firebaseio.com",
    projectId: "fir-web-codelab-d48d5",
    storageBucket: "fir-web-codelab-d48d5.appspot.com",
    messagingSenderId: "613496008685",
    appId: "1:613496008685:web:15a89add4eb203c0ca01e4",
    measurementId: "G-Z24DMW58LN"
  };

  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  // firebase.analytics()

  // FirebaseUI config
  const uiConfig = {
    credentialHelper: firebaseui.auth.CredentialHelper.NONE,
    signInOptions: [
      // Email / Password Provider.
      firebase.auth.EmailAuthProvider.PROVIDER_ID
    ],
    callbacks: {
      signInSuccessWithAuthResult: function(authResult, redirectUrl) {
        // Handle sign-in.
        // Return false to avoid redirect.
        return false;
      }
    }
  };

  // initilize the FirebaseUI widget using Firebase
  const ui = new firebaseui.auth.AuthUI(firebase.auth());

  // Listen(설정) to RSVP button clicks
  startRsvpButton.addEventListener("click", () => {
    // if a user has signed in, clicking this Button will allow the user to sign out
    if (firebase.auth().currentUser) {
      firebase.auth().signOut();
    } else {
      // 로그인 창을 보고 싶다고 firebaseui에 알립니다.
      ui.start("#firebaseui-auth-container", uiConfig);
    }
  });

  // Listen to the current Auth state
  firebase.auth().onAuthStateChanged(user => {
    // 현재 사용자가 있는 경우 RSVP 버튼을 로그 아웃 버튼으로 전환합니다.
    if (user) {
      startRsvpButton.textContent = "LOGOUT";
      guestbookContainer.style.display = "block"; // Show guestbook to logged-in users
      subscribeGuestbook();
      // Subscribe to the guestbook collection
      subscribeCurrentRSVP(user);
    } else {
      startRsvpButton.textContent = "RSVP";
      guestbookContainer.style.display = "none"; // Hide guestbook for non-logged-in users
      unsubscribeGuestbook();
      // Unsubscribe from the guestbook collection
      unsubscribeCurrentRSVP();
    }
  });

  // Listen to the form submission
  form.addEventListener("submit", e => {
    // Prevent the default form redirect
    e.preventDefault();
    // Write a new message to the database collection "guestbook"
    firebase
      .firestore()
      .collection("guestbook")
      .add({
        text: input.value,
        timestamp: Date.now(),
        name: firebase.auth().currentUser.displayName,
        userId: firebase.auth().currentUser.uid //a reference to the auto-generated unique ID that Firebase Authentication gives for all logged-in users.
      });
    // clear message input field
    input.value = "";
    // Return false to avoid redirect
    return false;
  });

  // Listen to guestbook updates
  function subscribeGuestbook() {
    // Create query for messages
    guestbookListener = firebase
      .firestore()
      .collection("guestbook")
      .orderBy("timestamp", "desc") // 최신 메시지를 맨 위에 표시
      // The ".onSnapshot function" takes one parameter: a callback function. The callback function is triggered when there are any changes to documents that match the query. This could be if a message gets deleted, modified, or added.
      .onSnapshot(snaps => {
        // Reset page
        guestbook.innerHTML = "";
        // Loop through documents in database
        snaps.forEach(doc => {
          // Create an HTML entry for each document and add it to the chat
          const entry = document.createElement("p");
          entry.textContent = doc.data().name + ": " + doc.data().text;
          guestbook.appendChild(entry);
        });
      });
  }

  // Unsubscribe from guestbook updates
  function unsubscribeGuestbook() {
    if (guestbookListener != null) {
      guestbookListener();
      guestbookListener = null;
    }
  }

  // Listen to RSVP responses
  rsvpYes.onclick = () => {
    // Get a reference to the user's document in the attendees collection
    const userDoc = firebase
      .firestore()
      .collection("attendees")
      .doc(firebase.auth().currentUser.uid);

    // If they RSVP'd yes, save a document with attending: true
    userDoc
      .set({
        attending: true
      })
      .catch(console.error);
  };
  rsvpNo.onclick = () => {
    // Get a reference to the user's document in the attendees collection
    const userDoc = firebase
      .firestore()
      .collection("attendees")
      .doc(firebase.auth().currentUser.uid);

    // If they RSVP'd no, save a document with attending: false
    userDoc
      .set({
        attending: false
      })
      .catch(console.error);
  };

  // Listen for attendee list
  firebase
    .firestore()
    .collection("attendees")
    .where("attending", "==", true)
    .onSnapshot(snap => {
      const newAttendeeCount = snap.docs.length;

      numberAttending.innerHTML = newAttendeeCount + " people going";
    });

  // Listen for attendee list
  function subscribeCurrentRSVP(user) {
    rsvpListener = firebase
      .firestore()
      .collection("attendees")
      .doc(user.uid)
      .onSnapshot(doc => {
        if (doc && doc.data()) {
          const attendingResponse = doc.data().attending;

          // Update css classes for buttons
          if (attendingResponse) {
            rsvpYes.className = "clicked";
            rsvpNo.className = "";
          } else {
            rsvpYes.className = "";
            rsvpNo.className = "clicked";
          }
        }
      });
  }

  function unsubscribeCurrentRSVP() {
    if (rsvpListener != null) {
      rsvpListener();
      rsvpListener = null;
    }
    rsvpYes.className = "";
    rsvpNo.className = "";
  }


}

main();
