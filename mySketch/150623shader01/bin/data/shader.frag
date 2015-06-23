uniform float u_time;
uniform vec2 u_resolution;


//----------
//vec4 red(){
//    return vec4(1.0, 0.0, 0.0, 1.0);
//}
//
//void main(){
//    gl_FragColor = red();
//}
//----------



void main(){
//    float red = abs(sin(u_time * 3.0));
//    float green = abs(sin(u_time * 4.0));
//    float blue = abs(sin(u_time * 5.0));
//    
    vec2 st = gl_FragCoord .xy / u_resolution;
    float red = abs(sin(u_time * 1.0 + st.x));
    float green = abs(sin(u_time * 2.0 + st.x));
    float blue = abs(sin(u_time * 1.7 + st.y));
    gl_FragColor = vec4(red, green, blue, 1.0);
}

