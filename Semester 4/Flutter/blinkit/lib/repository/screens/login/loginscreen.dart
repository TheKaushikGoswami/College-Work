import 'package:blinkit/repository/widgets/uihelper.dart';
import 'package:flutter/material.dart';

class LoginScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
      body: Center(
        child: Column(
          // mainAxisSize: MainAxisSize.min,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            UiHelper.CustomImage(img: "Blinkit Onboarding Screen.png"),
            SizedBox(height: 5),
            UiHelper.CustomImage(img: "image 10.png"),
            SizedBox(height: 5),
            UiHelper.CustomText(
              text: ("India's last minute app"),
              color: Color(0xFF000000),
              fontweight: FontWeight.bold,
              fontsize: 20,
              fontfamily: "bold",
            ),
            SizedBox(height: 5),
            Card(
              elevation: 4,
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(10),
              ),
              child: Container(
                height: 150,
                width: 350,
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(10),
                  color: Color(0XFFFFFFFF),
                ),
                child: Column(
                  children: [
                    SizedBox(height: 10),
                    UiHelper.CustomText(
                      text: "Kaushik",
                      color: Color(0xFF000000),
                      fontweight: FontWeight.w500,
                      fontsize: 12,
                    ),
                    SizedBox(height: 5),
                    UiHelper.CustomText(
                      text: "73708XXXXX",
                      color: Color(0xFF000000),
                      fontweight: FontWeight.w500,
                      fontsize: 10,
                    ),
                    SizedBox(height: 10),
                    SizedBox(
                      height: 40,
                      width: 290,
                      child: ElevatedButton(
                        onPressed: () {},
                        style: ElevatedButton.styleFrom(
                          backgroundColor: Color(0xFFE23744),
                          shape: RoundedRectangleBorder(
                            borderRadius: BorderRadius.circular(10),
                          ),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            UiHelper.CustomText(
                              text: "Login with",
                              color: Color(0xFFFFFFFF),
                              fontweight: FontWeight.bold,
                              fontsize: 12,
                            ),
                            SizedBox(width: 5),
                            UiHelper.CustomImage(img: "image 9.png"),
                          ],
                        ),
                      ),
                    ),
                    SizedBox(height: 5),
                    UiHelper.CustomText(
                      text:
                          "Access your saved addresses from Zomato automatically!",
                      color: Color(0xFF9C9C9C),
                      fontweight: FontWeight.normal,
                      fontsize: 10,
                    ),
                    SizedBox(height: 5),
                    UiHelper.CustomText(
                      text: "Or login with phone number",
                      color: Color(0xFF269237),
                      fontweight: FontWeight.normal,
                      fontsize: 10,
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
