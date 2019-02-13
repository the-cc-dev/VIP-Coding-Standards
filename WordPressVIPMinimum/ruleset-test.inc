
<?php // Squiz.WhiteSpace.SuperfluousWhitespace

// Generic.PHP.Syntax
while { // Error.
}

// Generic.PHP.NoSilencedErrors
if (@in_array( $array, $needle, true )) { // Error.
    echo '@';
}

// WordPress.Security.EscapeOutput
echo $hello; // Error.

// WordPress.Security.NonceVerification
function bar() {
	if ( ! isset( $_POST['test'] ) ) { // Error.
	}
}

// WordPress.Security.ValidatedSanitizedInput
if ( isset( $_POST['nonce'] ) && wp_verify_nonce( sanitize_text_field( $_POST['nonce'] ) ) ) {
	bar( $_POST['foo2'] ); // Error x 2.
	$foo2 = isset( $_POST['foo2'] ) ?? foo( sanitize_text_field( $_POST['foo2'] ) ); // Ok - exclude WordPress.Security.ValidatedSanitizedInput.MissingUnslash.
}

// WordPress.Security.PluginMenuSlug
add_menu_page( $page_title, $menu_title, $capability, __FILE__, $function, $icon_url, $position ); // Warning.

// WordPress.WP.EnqueuedResources
?> <script src="http://someurl/somefile.js"></script> <?php // Error.

// WordPress.WP.PostsPerPage
$args = array(
	'posts_per_page' => 999, // Warning.
);
_query_posts( 'posts_per_page=999' ); // Warning.
$query_args['posts_per_page'] = 999; // Warning.

// WordPress.WP.TimezoneChange
date_default_timezone_set( 'FooBar' ); // Error.

// WordPress.DB.PreparedSQL
$b = function () {
	global $wpdb;
	$listofthings = wp_cache_get( $listofthings );
	if ( ! $listofthings ) {
		$foo = "column = 'test'";
		$listofthings = $wpdb->query( 'SELECT something FROM somewhere WHERE ' . $foo ); // DB call ok; Error.
		wp_cache_set( 'foo', $listofthings );
	} 
};

// WordPress.DB.DirectDatabaseQuery
$baz = $wpdb->get_results( $wpdb->prepare( 'SELECT X FROM Y ' ) ); // Warning x 2.

// WordPress.DB.SlowDBQuery
$test = [
	'tax_query' => [], // Warning.
];
new WP_Query( array(
	'meta_query' => [], // Warning.
	'meta_key' => 'foo', // Warning.
	'meta_value' => 'bar', // Warning.
) );

// WordPress.WP.GlobalVariablesOverride
$GLOBALS['wpdb'] = 'test'; // Error.

// WordPress.PHP.StrictComparisons
if ( true == $true ) { // Warning.
}

// WordPress.CodeAnalysis.AssignmentInCondition
if ( $test = get_post( $post ) ) { // Warning.
}

// WordPress.PHP.StrictInArray
if ( true === in_array( $foo, $bar ) ) { // Warning.
}

// WordPress.Functions.DontExtract
extract( $foobar ); // Error.

// WordPress.WP.CronInterval
function my_add_weekly( $schedules ) {
	$schedules['every_6_mins'] = array(
		'interval' => 360,
		'display' => __( 'Once every 6 minutes' )
	);
	return $schedules;
}
add_filter( 'cron_schedules', 'my_add_weekly'); // Error.

// Generic.NamingConventions.ConstructorName
class TestClass extends MyClass
{
    function __construct() {
        parent::MYCLASS(); // Error.
        parent::__construct();
    }
}
class OldClass
{
    function OldClass() // Error.
    {
    }
}

// Generic.NamingConventions.ConstructorName
class TestClass extends MyClass {
    function TestClass() { // Error.
        parent::MyClass(); // Error.
        parent::__construct();
    }
}

// Generic.PHP.DisallowShortOpenTag
?> <?= esc_html( $var );

// Squiz.PHP.CommentedOutCode
// if (empty($this)) {echo 'This is will not work';} // Warning.

// Squiz.PHP.Eval
eval('$var = 4;'); // Error.

// WordPress.PHP.DiscouragedPHPFunctions
base64_decode( 'VGhpcyBpcyBhbiBlbmNvZGVkIHN0cmluZw=='); // Ok - exclude obfuscation group.
base64_encode( 'This is an encoded string' ); // Ok - exclude obfuscation group.
convert_uudecode( "+22!L;W9E(%!(4\"$`\n`" ); // Ok - exclude obfuscation group.
convert_uuencode( "test\ntext text\r\n" ); // Ok - exclude obfuscation group.
str_rot13( 'The quick brown fox jumps over the lazy dog.' ); // Ok - exclude obfuscation group.
serialize(); // Warning.
unserialize(); // Warning.
urlencode(); // Warning.
passthru( 'cat myfile.zip', $err ); // Warning.
$process = proc_open( 'php', $descriptorspec, $pipes, $cwd, $env ); // Warning.
$last_line = system( 'ls', $retval ); // Warning.
$handle = popen( '/bin/ls', 'r' ); // Warning.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_ini_set
ini_set(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_error_reporting
error_reporting(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_ini_alter
ini_alter(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_ini_restore
ini_restore(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_apache_setenv
apache_setenv(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_putenv
putenv(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_set_include_path
set_include_path(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_restore_include_path
restore_include_path(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_magic_quotes_runtime
magic_quotes_runtime(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_set_magic_quotes_runtime
set_magic_quotes_runtime(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_dl
dl(); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.system_calls_exec
exec( 'whoami' ); // Error.

// WordPress.PHP.DiscouragedPHPFunctions.system_calls_shell_exec
$output = shell_exec( 'ls -lart' ); // Error.

// WordPress.PHP.DevelopmentFunctions
var_dump(); // Warning.
var_export(); // Warning.
print_r(); // Warning.
trigger_error(); // Warning.
set_error_handler(); // Warning.
debug_backtrace(); // Warning.
debug_print_backtrace(); // Warning.
wp_debug_backtrace_summary(); // Warning.

// WordPress.PHP.DevelopmentFunctions.prevent_path_disclosure_phpinfo
phpinfo(); // Error.

// WordPress.PHP.DevelopmentFunctions.error_log_error_log
error_log(); // Error.

// WordPress.WP.AlternativeFunctions
curl_init(); // Warning.
curl_close( $ch ); // Warning.
CURL_getinfo(); // Warning.
parse_url( 'http://example.com/' ); // Warning.
$json = json_encode( $thing ); // Warning.
readfile(); // Warning.
fopen(); // Warning.
fsockopen(); // Warning.
pfsockopen(); // Warning.
fclose(); // Warning.
fread(); // Warning.
rand(); // Warning.
mt_rand(); // Warning.
srand(); // Warning.
mt_srand(); // Warning.
wp_rand(); // OK.
parse_url($url, PHP_URL_SCHEME); // Warning.

// WordPressVIPMinimum.Functions.RestrictedFunctions.get_posts_get_children
get_children(); // Error.

// WordPressVIPMinimum.Variables.VariableAnalysis
function foo() {
	$a = 'Hello';
	$c = compact( $a, $b ); // Warning x 2.
	try {
		do_something_silly();
	} catch ( Exception $e ) {} // Ok.
}

<!-- The below rules are implicitly included via WordPressVIPMinimum -->
// WordPressVIPMinimum.Classes.DeclarationCompatibility
class MyWidget extends WP_Widget {
	function widget() {
	} // Error.
}

// WordPressVIPMinimum.Classes.RestrictedExtendClasses
class BadTestClass extends WP_CLI_Command { } // Warning.

// WordPressVIPMinimum.Compatibility.Robotstxt.DoRobotsTxtFound
add_action( 'do_robotstxt', 'my_do_robotstxt');

// WordPressVIPMinimum.Hooks.PreGetPosts
add_action( 'pre_get_posts', function( $wp_query ) {
	if ( ! $wp_query->is_search() ) {
		$wp_query->set( 'cat', '-5' ); // Warning.
	}
} );

// WordPressVIPMinimum.Cache.CacheValueOverride
$bad_wp_users = wp_cache_get( md5( self::CACHE_KEY . '_wp_users'), self::CACHE_GROUP );
$bad_wp_users = false; // Error.



// WordPressVIPMinimum.Constants.RestrictedConstants
if ( A8C_PROXIED_REQUEST === true ) { // Warning.
}

// WordPressVIPMinimum.Files.IncludingFile
require_once "my_file.php"; // Error.

// WordPressVIPMinimum.Functions.CheckReturnValue
$my_theme_options = get_option( 'my_theme', false );
if ( array_key_exists( 'key', $my_theme_options ) ) { // Error.
}

// WordPressVIPMinimum.Performance.RegexpCompare + WordPress.DB.SlowDBQuery
$query_args = array(
	'posts_per_page' => 1,
	'post_status' => 'draft',
	'meta_key' => 'my_awesome_meta_key', // WordPress.DB.SlowDBQuery. // Warning.
	'meta_value' => "(^|\n|\r\n)99999($|\n|\r\n)", // WordPress.DB.SlowDBQuery. // Warning.
	'meta_compare' => 'REGEXP', // Error.
);

// WordPressVIPMinimum.Performance.RemoteRequestTimeout
wp_remote_post( $this->endpoint, array(
        'method'      => 'POST',
        'timeout'     => 45, // Error.
        'httpversion' => '1.1',
        'blocking'    => false,
        'body'        => wp_json_encode( $this->logs, JSON_UNESCAPED_SLASHES ),
    )
);

// Squiz.PHP.Eval
eval( ';' ); // Error.

// WordPressVIPMinimum.Functions.RestrictedFunctions
wpcom_vip_irc(); // Error.

get_children(); // Error + Message.

attachment_url_to_postid(); // Error.

str_replace( 'foo', 'bar', 'foobar' ); // Error.

wpcom_vip_get_term_link(); // Warning.

wpcom_vip_get_term_by(); // Warning.

wpcom_vip_get_category_by_slug(); // Warning.

get_cat_ID(); // Ok.

get_category_link(); // Ok.

get_tag_link(); // Ok.

get_category_by_slug(); // Ok.

get_term_by(); // Ok.

get_term_link(); // Ok.

wp_mail(); // Warning.

mail(); // Warning.

dbDelta(); // Error.

flush_rewrite_rules(); // Error.
global $wp_rewrite;
$wp_rewrite->flush_rules(); // Error.

// WordPress.CodeAnalysis.AssignmentInCondition.
if ( $a = 1 ) {} // Warning.

add_option( 'taxonomy_rating_' . $obj->term_id ); // Warning.

//wpcom_vip_load_plugin( 'disqus' ); // Warning.

echo "<a href='" . esc_attr( $some_var ) . "'></a>"; // Error.

$hello = true === isset( $_GET['utm_medium'] ) ? true : false; // Warning.

wp_safe_redirect( 'https.//vip.wordpress.com' ); // Error.

is_multi_author(); // Warning.

include( 'non-php-file.svg' ); // Error. Including non-php file.

echo file_get_contents( 'non-php-file.svg' ); // phpcs:ignore WordPress.Security.EscapeOutput.OutputNotEscaped -- Preferred way of including SVG/CSS file.

// phpcs:set WordPressVIPMinimum.VIP.CronInterval min_interval 600
add_filter( 'cron_schedules', 'my_add_weekly' ); // Error. 6 min.
// phpcs:set WordPressVIPMinimum.VIP.CronInterval min_interval 900

thisisasyntaxerror! // Error.

// WordPressVIPMinimum.Functions.RestrictedFunctions.site_option_add_site_option
add_site_option( 'foo', $bar ); // Error.

// WordPressVIPMinimum.Functions.RestrictedFunctions.site_option_update_site_option
update_site_option( $bar, $foo, true ); // Error.

// WordPressVIPMinimum.Functions.RestrictedFunctions.site_option_delete_site_option
delete_site_option( $foo ); // Error.

// PSR2.Files.ClosingTag + Squiz.WhiteSpace.SuperfluousWhitespace
?>


