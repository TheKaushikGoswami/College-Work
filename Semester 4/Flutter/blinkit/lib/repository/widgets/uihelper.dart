import 'package:flutter/material.dart';

class UiHelper {
  static CustomImage({required String img, double? height, double? width}) {
    return Image.asset(
      "assets/images/$img",
      height: height,
      width: width,
    );
  }

  static CustomText({
    required String text,
    required Color color,
    required FontWeight fontweight,
    String? fontfamily,
    required double fontsize,
  }) {
    return Text(
      text,
      style: TextStyle(
        color: color,
        fontWeight: fontweight,
        fontFamily: fontfamily ?? "regular",
        fontSize: fontsize,
      ),
    );
  }
}
